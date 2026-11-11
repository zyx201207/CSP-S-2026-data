#include <bits/stdc++.h>
using namespace std;
string arn,brn;
string ftr,fdr;
map<char,int> mae;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>arn>>ftr>>brn>>fdr;
	mae['A']=1;
	mae['B']=1;
	mae['C']=1;
	mae['D']=2;
	mae['F']=2;
	if(arn==brn) {
		cout<<1;
		if(ftr[0]==fdr[0]&&ftr[1]==fdr[1]) {
			cout<<1;
			if(mae[ftr[2]]==mae[fdr[2]]){
				cout<<1;
				if(mae[ftr[2]]==2||ftr[2]=='B'||fdr[2]=='B'){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<"00";
			}
			} else {
			cout<<"000";
		}
	} else {
		cout<<"0000";
	}
	return 0;
}
