//郭昕宇 西安市铁一中学 SN-J00713 
#include<bits/stdc++.h>
using namespace std;
int mp[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	int p=(b[0]-'0')*10+(b[1]-'0'),q=(d[0]-'0')*10+(d[1]-'0');
	if(p!=q){
		cout<<"000";
		return 0;
	}
	cout<<1;
	mp[(b[2]-'A')]=1,mp[d[2]-'A']=1;
	int k1,k2;
	k1=k2=0;
	for(int i=0;i<=4;i++){
		if(mp[i]==1){
			if(k1==0)k1=i;
			else k2=i;
		}
	}
	if(k2>2&&k1!=3){
		cout<<"00";
		return 0;
	}
	cout<<1;
	if(abs(k1-k2)==1&&k1!=2)cout<<1;
	else cout<<0;
	return 0;
}
