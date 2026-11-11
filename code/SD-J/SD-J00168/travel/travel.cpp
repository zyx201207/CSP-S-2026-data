#include<bits/stdc++.h>
#define int long long
#define INF (1ll<<62)
#define pii pair<int,int>
using namespace std;
string che1,zuo1,che2,zuo2;
int a[500];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>che1>>zuo1>>che2>>zuo2;
	if(che1!=che2){
		cout<<"0000";
		return 0;
	}	
	else if(zuo1[0]!=zuo2[0] or zuo1[1]!=zuo2[1]){
		cout<<"1000";
		return 0;
	}
	else{
		a['A']=-1,a['B']=-2,a['C']=-3;
		a['D']=1,a['F']=2;
		if((a[zuo1[2]]>0 and a[zuo2[2]]>0) or (a[zuo1[2]]<0 and a[zuo2[2]]<0)){
			cout<<"111";
			if(abs(a[zuo1[2]]-a[zuo2[2]])>1){
				cout<<"0";
				return 0;
			}
			else{
				cout<<"1";
				return 0;
			}
		}
		else{
			cout<<"1100";
			return 0; 
		}
	}
	return 0;
}

