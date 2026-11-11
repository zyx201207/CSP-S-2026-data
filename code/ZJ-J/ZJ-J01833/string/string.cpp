#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans,b[30],c[30],su,sm,mid;
char ch[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>ch[i];
		ans+=a[i];
	}
	long long t=0;
	if(ans%2==0){
		for(int i=1;i<=n;i++){
			t+=a[i];
			if(t==ans/2){
				mid=i;
				break;
			}
			if(t>ans/2){
				n++;
				if(mid==0)mid=i;
				long long l=a[i];
				a[i]=ans/2-(t-a[i]);
				l-=a[i];
				char cdf=ch[i];
				for(int j=i+1;j<=n;j++){
					long long ll=a[j];
					char cg=ch[j];
					a[j]=l;
					ch[j]=cdf;
					l=ll;
					cdf=cg;
				}
				break;
			}
		}
	}
	else{
		for(int i=1;i<=n;i++){
			t+=a[i];
			if(t==ans/2+1){
				mid=i;
				a[i]--;
				ans--;
				break;
			}
			if(t>ans/2+1){
				n++;
				if(mid==0)mid=i;
				long long l=a[i];
				a[i]=ans/2-(t-a[i]);
				l-=a[i]+1;
				char cdf=ch[i];
				for(int j=i+1;j<=n;j++){
					long long ll=a[j];
					char cg=ch[j];
					a[j]=l;
					ch[j]=cdf;
					l=ll;
					cdf=cg;
				}
				break;
			}
		}
	}
//	cout<<mid<<'\n';
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<" "<<ch[i]<<"\n";
//	}
	if(a[mid]==0) mid--;
	long long r=n,ans=0;
	for(int i=1;i<=mid;i++){
		long long sum=0,dif=0;
		t=a[i];
		for(int j=r;j>mid;j--){
			sum+=a[j];
			if(ch[i]!=ch[j]) dif+=a[j];
			if(sum==t){
				r=j-1;
				break;
			}
			if(sum>t){
				a[j]-=t-(sum-a[j]);
				dif-=a[j];
				r=j;
				break;
			}
//			cout<<"dfsdf";
//			for(int k=1;k<=n;k++){
//				cout<<a[k]<<" "<<ch[k]<<"\n";
//			}
		}
		ans+=dif;
	}
	cout<<ans;
	return 0;
}