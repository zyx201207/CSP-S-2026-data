#include <bits/stdc++.h>
using namespace std;
vector< vector<int> > blocksA, blocksB;
void gba(const vector< vector<bool> > &path, int k, vector<int> baa, vector<int> bba, vector<bool> used){
	if(k == 0){
		blocksA.push_back(baa);
		blocksB.push_back(bba);
		return;
	}
	for(int as=0;as<baa.size();as++){
		for(int i=0;i<path[baa[as]].size();i++){
			if(!used[i] && path[baa[as]][i]){
				vector<int> cpy = baa;
				cpy.push_back(baa[as]);
				vector<bool> coy = used;
				coy[i] = true;
				gba(path, k-1, cpy, bba, coy);
			}
		}
	}
	for(int bs=0;bs<bba.size();bs++){
		for(int i=0;i<path[bba[bs]].size();i++){
			if(!used[i] && path[bba[bs]][i]){
				vector<int> cpy = bba;
				cpy.push_back(bba[bs]);
				vector<bool> coy = used;
				coy[i] = true;
				gba(path, k-1, baa, cpy, coy);
			}
		}
	}
}
int main(void){
	ifstream fin("hub.in", ios_base::in);
	ofstream fout("hub.out", ios_base::out);
	int c, t;
	fin >> c >> t;
	while(t--){
		int n, k;
		fin >> n >> k;
		vector< vector<bool> > path(n+2, vector<bool>(n+2, false));
		for(int i=0;i<n-1;i++) {
			int u, v;
			fin >> u >> v;
			path[u][v] = true;
			path[v][u] = true;
		}
		int val = numeric_limits<int>::max();
		for(int a=0;a<n-1;a++){
			for(int b=a+1;b<n;b++){
				vector<int> al, bl;
				al.push_back(a);
				bl.push_back(b);
				vector<bool> vs(n, false);
				gba(path, k, al, bl, vs);
				for(int i=0;i<blocksA.size();i++){
					vector< vector<bool> > new_path = path;
					new_path.push_back(vector<bool>(n + 2, false));
					new_path.push_back(vector<bool>(n + 2, false));
					for(int j=0;j<blocksA[i].size();j++){
						for(int p=0;p<n+2;p++){
							if(new_path[blocksA[i][j]][p])
								new_path[n][p] = true, new_path[p][n] = true;
						}
					}
					for(int j=0;j<blocksB[i].size();j++){
						for(int p=0;p<n+2;p++){
							if(new_path[blocksB[i][j]][p])
								new_path[n+1][p] = true, new_path[p][n+1] = true;
						}
					}
					int sz = n + 2 - blocksA[i].size();
					vector< vector<bool> > res(sz, vector<bool>(sz, false));
					int joffset=0, poffset=0;
					for(int j=0;j<n+2;j++){
						bool jflag = false;
						for(int r=0;r<blocksA[i].size() && !jflag;r++)
							if(j == blocksA[i][r])
								jflag = true;
						for(int r=0;r<blocksB[i].size() && !jflag;r++)
							if(j == blocksB[i][r])
								jflag = true;
						if(jflag){
							joffset++;
							continue;
						}
						for(int p=0;p<n+2;p++){
							bool pflag = false;
							for(int r=0;r<blocksA[i].size() && !pflag;r++)
								if(p == blocksA[i][r])
									pflag = true;
							for(int r=0;r<blocksB[i].size() && !pflag;r++)
								if(p == blocksB[i][r])
									pflag = true;
							if(pflag){
								poffset++;
								continue;
							}
							res[j-joffset][p-poffset] = new_path[j][p];
						}
					}
					vector<int> cdis(sz, -1);
					cdis[sz-1] = 0;
					cdis[sz-2] = 0;
					for(int p=sz-1;p>0;p--){
						for(int r=sz-2;r>=0;r--){
							if(res[p][r]){
								if(cdis[p] == -1 && cdis[r] == -1) continue;
								if(cdis[p] == -1) cdis[p] = cdis[r] + 1;
								if(cdis[r] == -1) cdis[r] = cdis[p] + 1;
								if(cdis[p] > cdis[r] + 1) cdis[p] = cdis[r] + 1;
								if(cdis[r] > cdis[p] + 1) cdis[r] = cdis[p] + 1;
							}
						}
					}
					int ans = 0;
					for(int i=0;i<sz;i++)
						ans = max(ans, cdis[i]);
					val = min(ans, val);
				}
				blocksA.clear();
				blocksB.clear();
			}
		}
		fout << val << endl;
	}
	return 0;
}

