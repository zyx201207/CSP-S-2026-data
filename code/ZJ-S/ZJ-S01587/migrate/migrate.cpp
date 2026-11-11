#include<bits/stdc++.h>
using namespace std;
long long n,t,d,a[2345678],b[2345678],c[2345678],ans,s[2345678];
int main(){
	freopen("migrate6.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>t;
	if(t<=10){
		cin>>t;
		while(t--){
			ans=0;
			scanf("%lld%lld",&n,&d);
			for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
			sort(a+1,a+n+1);
			for(int i=n;i;i--){
//				cout<<i<<":";
				b[i]=1;
				c[i]=0;
				for(int j=i+1;j<=n;j++){
					b[j]=0;
					c[j]=1e18;
				}
				for(int j=i;j<=n;j++){
						for(int k=j+1;a[k]-a[j]<=d&&k<=n;k++){
						if(c[j]+1==c[k])
						b[k]+=b[j];
						if(c[j]+1<c[k]){
							c[k]=c[j]+1;
							b[k]=b[j];
						}
					}
					if(b[j]==2){
						ans++;
//						cout<<j<<" ";
					}
//					cout<<i<<" "<<j<<" "<<b[j]<<" "<<c[j]<<" "<<ans<<endl;
//					if(b[j]>2)break;
				}
//				cout<<"\n"<<i<<":"<<ans<<endl;
			}
			printf("%d\n",ans);
		}
	}
	else{
		cin>>t;
		while(t--){
			ans=0;
			scanf("%lld%lld",&n,&d);
			for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
			sort(a+1,a+n+1);
			for(int i=1,j=1;i<n;i++){
				while(j<n&&a[j+1]<=d+a[i])j++;
				b[i]=j;
			}	
			b[n]=0;
			c[n+1]=0;
			for(int i=n;i;i--){
				if(b[i]==i+1)s[i]=s[i+1]+1;
				else s[i]=0;
			}
//			cout<<n<<" "<<ans<<endl;
			for(int i=n;i>0;i--){
				if(b[i]>i+1&&b[b[i]-1]-b[b[i]-2]){
					c[i]=b[b[i]-1]-b[b[i]-2]+s[b[b[i]-1]-1]-(s[b[b[i]-1]-1]!=0);
//					c[i]=s[b[b[i]-2]];
				}
				else if(b[i]==i+1){
					c[i]=c[i+1];
				}
				else c[i]=0;
				ans=ans+c[i];
//				cout<<i<<" "<<b[i]<<" "<<s[i]<<" "<<ans<<endl;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
//10 333333333333333327
//-1000000000000000000 -666666666666666673 -333333333333333346 -111111111111111128 111111111111111090 222222222222222199 333333333333333308 444444444444444417 666666666666666635 999999999999999962
//8 3
//0 1 2 4 8 10 11 13
//6 3
//0 1 2 3 4 7
//0 2
//5 3
//-2 -1 0 1 2
//6 2
//-4 -3 -2 -1 3 6
