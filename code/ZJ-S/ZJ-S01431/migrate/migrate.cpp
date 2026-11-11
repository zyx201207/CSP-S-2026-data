#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[1000005],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int l=1;l<=n;l++){
			for(int r=l+3;r<=n;r++){
				long long lst=a[l],f=1;
				vector<int>s1,s2;
				for(int i=l+1;l<=r;i++){
					int j=i;
					if(a[j]>lst+d){
						f=0;
						break;	
					}
					while(a[j]<=lst+d&&j<=r){
						j++;
					}
					if(j>r){
						break;
					}
					else{
						s1.push_back(j-1);
						lst=a[j-1];
						i=j-1;
					}
				}
				if(f){
					lst=a[r];
					for(int i=r-1;i>=l;i--){
						int j=i;
						while(a[j]>=lst-d&&j>=l){
							j--;
						}
						if(j<l){
							break;
						}
						else{
							s2.push_back(j+1);
							lst=a[j+1];
							i=j+1;
						}
					}
					int x=s1.size(),cnt=0,sum=0;
					for(int i=0,j=x-1;i<x&&j>=0;i++,j--){
						if(s1[i]!=s2[j]){
							cnt++;
							sum+=abs(s1[i]-s2[j]);
						}
					}
					if(cnt==1&&sum==1){
						ans++;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}