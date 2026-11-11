#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,ans,shazi;
int a[500005];
int d[500005];
int dp;
int shi[500005];
int t[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	int sum1=0,sum2=0,cnt1=0,cnt2=0;
	int gou=m;
    	for(int i=1;i<=n;i++){
		cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
    	t[a[i]]++;
    	shi[a[i]]++;
    	d[i]=a[i]-a[i-1];
	}
    int flag=0;
	for(int i=1;i<=n;i++){
		for(int j=2;j<=n;j++){
			if(d[i]!=d[j]||d[i]!=d[j+1]){
				flag=0;
				break;
			    }
			    else flag=1;
			}
	    if(flag==0)break;
		}
	if(flag==1){
		int q=d[1];
		while(m>0){
			cnt++;
			m-=q;
			q+=d[1];
		}
		cout<<cnt<<endl;
		return 0;
	}
	else  m=gou,cnt=0;
	sort(t+1,t+n+1,greater<int>());
    for(int i=n/2;i>=1;i--){
    	if(m-d[i]>=0&&d[i]!=0)m-=d[i],cnt1++;
	}
	cnt1+=shi[a[n/2]];
	m=gou;
	 for(int i=n/2+1;i>=1;i--){
    	if(m-d[i]>=0&&d[i]!=0)m-=d[i],cnt2++;
	}
	cnt2+=shi[a[n/2+1]];
	cnt=max(cnt1,cnt2);
	m=gou;
	int min_d=INT_MAX,min_i;
	for(int i=1;i<=n;i++){
		if(d[i]<=min_d)min_d=d[i],min_i=i;
	}
	for(int i=min_i;i>=0&&m-d[i]>=0;i++){
		if(m-d[i]>=0&&d[i]!=0)m-=d[i],sum1++;
	}
	sum1+=shi[a[min_i]];
	for(int i=min_i;i<=n&&m-d[i]>=0;i++){
		if(m-d[i]>=0&&d[i]!=0)m-=d[i],sum2++;
		
	}
	sum2+=shi[a[min_i]];
	long long sum;
	sum=max(sum1,sum2);
	shazi=sum;
    ans=max(cnt,shazi);
	cout<<ans<<endl;
	return 0;
}
