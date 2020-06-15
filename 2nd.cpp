#include <bits/stdc++.h>

using namespace std;

const int N = 200 + 21;

int days[N], cost[N], child[N], vis[N], dp[N][N], par[N][N], sum[N][N];
vector < int > tps, sub[N], path;

void dfs(int u) {
	vis[u] = 1;
	if(child[u] != -1 && vis[child[u]] == 0) {
		dfs(child[u]);
	}
	tps.push_back(u);
}

void make(int u, int pos) {
	vis[u] = 1;
	sub[pos].push_back(u);
	if(child[u] != -1) {
		make(child[u], pos);
	}
}

void upd(int i, int j, int a, int p) {
	if(dp[i][j] > a) {
		dp[i][j] = a;
		par[i][j] = p;
	}
}

void rec(int i, int j, int k) {
	if(i + j) {
		if(par[i][j]) {
			path.push_back(sub[k][j]);
			rec(i, j - 1, k);
		}
		else {
			path.push_back(sub[0][i]);
			rec(i - 1, j, k);
		}
	}
}

int main() {
	int t;
	scanf("%d", &t);
	for(int tt = 1; tt <= t; tt++) {
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n ; i++) {
			scanf("%d", days + i);
		}
		for(int i = 1; i <= n; i++) {
			scanf("%d", cost + i);
		}
		int m;
		scanf("%d", &m);
		memset(child, -1, sizeof child);
		while(m--) {
			int u, v;
			scanf("%d%d", &u, &v);
			child[u] = v;
		}
		tps.clear();
		memset(vis, 0, sizeof vis);
		for(int i = 1; i <= n; i++) {
			if(vis[i] == 0) {
				dfs(i);
			}
		}
		int subsize = 0;
		memset(vis, 0, sizeof vis);
		for(int i = 0; i < N; i++) {
			sub[i].clear();
		}
		for(int i = tps.size() - 1; i >= 0; i--) {
			if(vis[tps[i]] == 0) {
				sub[subsize].push_back(0);
				make(tps[i], subsize++);
			}
		}
		memset(sum, 0, sizeof sum);
		for(int i = 0; i < subsize; i++) {
			for(int j = 1; j < sub[i].size(); j++) {
				sum[i][j] = sum[i][j - 1] + days[sub[i][j]];
			}
		}
		for(int i = 1; i < subsize; i++) {
			memset(dp, 127, sizeof dp);
			dp[0][0] = 0;
			for(int j = 0; j < sub[0].size(); j++) {
				for(int k = 0; k < sub[i].size(); k++) {
					if(j) {
						upd(j, k, dp[j - 1][k] + (sum[0][j] + sum[i][k]) * cost[sub[0][j]], 0);
					}
					if(k) {
						upd(j, k, dp[j][k - 1] + (sum[0][j] + sum[i][k]) * cost[sub[i][k]], 1);
					}
				}
			}
			path.clear();
			rec(sub[0].size() - 1, sub[i].size() - 1, i);
			path.push_back(0);
			reverse(path.begin(), path.end());
			sub[0] = path;
			for(int j = 1; j < sub[0].size(); j++) {
				sum[0][j] = sum[0][j - 1] + days[sub[0][j]];
			}
		}
		int ans = 0;
		for(int i = 1; i < sub[0].size(); i++) {
			ans += sum[0][i] * cost[sub[0][i]];
		}
		printf("Case %d: %d\n", tt, ans);
	}
	return 0;
}
