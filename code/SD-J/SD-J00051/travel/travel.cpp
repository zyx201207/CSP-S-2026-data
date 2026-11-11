#include<bits/stdc++.h>
using namespace std;
map<char,int>mp,mp2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	mp['A']=1;mp['B']=1;mp['C']=1;mp['D']=0;mp['E']=0;
	mp2['A']=1;mp2['B']=2;mp['C']=3;
	string ax,bx,ar,br;cin>>ar>>br>>ax>>bx;
	if(ar==ax){
		cout<<"1";
		if(br[0]==bx[0]&&br[1]==bx[1]){
			cout<<"1";
			if(mp[br[2]]==mp[bx[2]]){
				cout<<"1";
				if(mp[br[2]]==0||abs(mp2[br[2]]-mp2[br[2]])==1){
					cout<<"1";
				}else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	
	return 0;
}
