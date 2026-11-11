#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
#define endl '\n'
#define ll long long
#define ull unsigned long long

int a[500005];

signed main(){
	
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	bool flag=0;
	int n,m; cin>>n>>m;
	
	for(int i=1;i<=n;i++)
		cin>>a[i];
	
	int Cha=0,lasCha=0;
	for(int i=2;i<=n;i++){
		Cha=a[i]-a[i-1];
		if(i!=2 && Cha!=lasCha){
			flag=1;
			break;
		}
		lasCha=Cha;
	}
	if(flag==0){
		int x=1;
		while(1){
			if(((Cha+x*Cha)*x)/2<m) x=x+1;
			else if(((Cha+x*Cha)*x)/2==m) break;
			else if(((Cha+x*Cha)*x)/2>m){
				x=x-1; 
				break;
			}
		}
		cout<<x<<endl;
		return 0;
	}
	
	sort(a+1,a+n+1);
	
	int MXans=0;
	
	for(int i=1;i<=n;i++){
			
		int j=i,tmp=m,ans=0;
		while(j>=1){
			
			if(tmp-(a[i]-a[j])>=0){
				tmp=tmp-(a[i]-a[j]);
				ans=ans+1,j=j-1;				
			}else break;
			
		}
		MXans=max(MXans,ans);
	}
	cout<<MXans;
	
	return 0;
}
