#include<bits/stdc++.h>
using namespace std;
int a[2000000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,w;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long ans=-1000000;
	long long cnt=0;
	for(int i=2;i<=n;i++){
		w=m;
		cnt=0;
		for(int j=i-1;j>=1;j--){
			if(w>0){
				if(w<(a[i]-a[j])){
					break; 
				}
				w=w-(a[i]-a[j]);
				//cout<<w<<" ";
				cnt++;
			}	
			else{
				break;
			}
		}
		ans=max(cnt,ans);
	}
	cout<<ans+1;
	return 0;
}

