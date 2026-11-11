#include<bits/stdc++.h>//jm99
#define endl '\n'//jm99
#define ll long long //jm99
using namespace std;//jm99
int n,m,a[200005],ans;//jm99
int main(){//jm99
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);//jm99
	freopen("and.in","r",stdin);//jm99
	freopen("and.out","w",stdout);//jm99
    cin>>n>>m;//jm99
    for(int i=1;i<=n;i++)cin>>a[i];//jm99
    if(m==1){//jm99
    	int Max=0;//jm99
    	for(int i=1;i<=n;i++)Max=max(Max,a[i]);//jm99
		cout<<Max;//jm99
		return 0; //jm99
	}//jm99
	if(m==n){//jm99
    	ans=a[1];//jm99
    	for(int i=1;i<=n;i++)ans=(ans&a[i]);//jm99
    	cout<<ans;//jm99
    	return 0;//jm99
	}//jm99
	if(m==2){//jm99
		for(int i=1;i<=n;i++){//jm99
			for(int j=1;j<=m;j++){//jm99
				if(i==j)continue;//jm99
				ans=max(ans,(a[i]&a[j]));//jm99
			}//jm99
		}//jm99
		cout<<ans;//jm99
		return 0;//jm99
	}//jm99
	int Max=0;//jm99
    for(int i=1;i<=n;i++)Max=max(Max,a[i]);//jm99
	cout<<Max;	//jm99
    return 0;//jm99
}//jm99


