#include<bits/stdc++.h>
using namespace std;

const int MaX = 5 * 1e5 + 106;
const long long Mnx = 1e8 + 2;
long long n,m;
long long A[MaX];
int B[Mnx];
long long ua,vb,ub,sac,sbc;
long long zds;
int zgsmax = -244;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m; 
	cin >> A[1] >> A[2];
	vb = A[2] - A[1];
	for(int i = 3;i <= n;i ++){
		cin >> A[i];
		if(A[i] != A[i - 1]) ua += 1;
		if(A[i] - A[i - 1] != vb) ub += 1;
		B[A[i]] += 1;
	}
	if(ua == 0){
		int uac;
		for(int i = 1;i <= n;i ++){
			sac = i * (i - 1);
			if(sac == m){
				uac = i;
				break;
			}
			if(sac > m){
				uac = i - 1;
				break;
			}
		}
		cout << uac;
		return 0;
	}
	else if(ub == 0){
		int ubc;
		for(int i = 1;i <= n;i ++){
			sbc = i * (i - 1) * vb;
			if(sbc == m){
				ubc = i;
				break;
			}
			if(sbc > m){
				ubc = i - 1;
				break;
			}
		}
		cout << ubc;
		return 0;
	}
	else{
		for(int i = 1;i <= n;i ++){
			int dsi [MaX] = {},zgs;
			zds = 0;
			for(int j = 1;j <= n;j ++){
				dsi[j] = A[i] - A[j];
			}
			sort(dsi + 1,dsi + 1 + n);
			int l = 0;
			zds = 0;
			for(int k = 1;k <= n;k ++){
				if(dsi[k] >= 0){
					zds += dsi[k];
					l += 1;
				}
				if(zds == m){
					zgs = l;
					break;
				}
				if(zds > m){
					zgs = l - 1;
					break;
				}
			}
			if(zgs >= zgsmax){
				zgsmax = zgs;
			}
		}
		cout << zgsmax;
		return 0;	   
	}
	return 0;
} 