#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005],b[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int c,cnt=0;
		cin>>c;
		while(c){
			a[i]*=10;
			if(c%2==0){
				cnt++;
			}
			a[i]+=c%2;
			c/=2;
		}
		a[i]*=pow(10,cnt-1);
	}
	int c=1,mx=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int ans=0,ans1=0;
			for(int l=j;l<=m-1+j;l++){
				if(j==l){
					int s1=a[i],s2=a[l],cnt1=0;
					while(max(s1,s2)){
						cnt1++;
						ans+=((s2%10)&(s1%10))*pow(2,cnt1);
						ans1*=10;
						ans1+=((s2%10)&(s1%10));
						s1/=10;
						s2/=10;
					}
					if(m==2){
						break;
					}
				}
				int cnt=0,c1=a[j],c2=ans1;
				while(max(c1,c2)){
					cnt++;
					ans+=((c2%10)&(c1%10))*pow(2,cnt);
					c1/=10;
					c2/=10;
				}
			}
			mx=max(mx,ans);
		}
	}
	cout<<mx;
	return 0;
}
