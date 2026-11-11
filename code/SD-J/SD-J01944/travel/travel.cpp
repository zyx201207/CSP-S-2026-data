#include<bits/stdc++.h>
using namespace std;
string cr,sr,cx,sx;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> cr >> sr >> cx >> sx;
	long long lr = sr.length()-1,lx = sx.length()-1,srr,sxx;
	if(sr[lr] == 'A' || sr[lr] == 'B' || sr[lr] == 'C'){
		srr = 1;
	}else{
		srr = 0;
	}if(sx[lx] == 'A' || sx[lx] == 'B' || sx[lx] == 'C'){
		sxx = 1;
	}else{
		sxx = 0;
	}
	bool jj;
	if(cr == cx){
		cout << "1";
		for(int i = 1; i < lr; i++){
			if(sr[i] == sx[i]){
				jj = 1;
			}else{
				jj = 0;
				break;
			}
		}if(jj){
			cout << "1"; 
		}else{
			cout << "000";
			return 0;
		}
		if(srr == sxx){
			cout << "1";
			if(sr[lr] - sx[lx] == 1 || sr[lr] - sx[lx] == -1){
				cout << "1";
			}else{
				cout << "0";
				return 0; 
			}
		}else{
			cout << "00";
			return 0;
		}
	}else{
		cout << "0000";
	}
	return 0;
}
