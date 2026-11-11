#include<bits/stdc++.h>
using namespace std;
long long a[541654],b[54165416];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	long long sum=0;
	long long ans=0,ans1=0,ans2=0,ans3=0;
	long long minn=54165416,maxx=1;
	cin>>n>>m;
	if(m==0){
		for(long long i=1;i<=n;i++){
			cin>>a[i];
			b[a[i]]++;
			maxx=max(b[a[i]],maxx);
		}
		cout<<maxx;
	}
	else{
		for(long long i=1;i<=n;i++){
			cin>>a[i];
			sum+=a[i];
		}
		sort(a+1,a+n+1);
		ans=sum/n;
		int c=0;
		for(long long i=1;i<=n;i++){
			if(abs(a[i]-ans)>minn){
				ans1=a[i-1];
				ans2=i;
				c=1;
				break;
			}
			minn=min(abs(a[i]-ans),minn);
		}
		if(c==0){
			ans1=a[n];
			ans2=n;
		}
		for(long long i=1;i<=ans2;i++){
			if(m<(ans1-a[i])||m<0||(ans1-a[i])<0){
				break;
			}
			a[i]=ans1;
			m-=ans1-a[i];
			ans3++;
		}
		cout<<ans3;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
