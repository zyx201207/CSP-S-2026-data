#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+100;
char ch[N];
int a[N];
int sch[N],wsq[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long cnt=0,sum=0,cnt1=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>ch[i];
		cnt+=a[i];
		cnt1+=a[i];
	}cnt=cnt/2+cnt%2;
	long long l=0,r=0,f=0;
	for(int i=1;i<=n;i++){
		if(sum+a[i]>=cnt&&sum<=cnt){
			f=i;
			r=sum+a[i]-cnt;
			l=a[i]-r;
			if(sum+l==cnt&&l==1&&cnt1%2!=0) l=0;
			break;
		}sum+=a[i];
	}cnt=0;
	sum=1;
	for(int i=1;i<f;i++){
		sch[i]=a[i];
	}for(int i=n;i>f;i--){
		wsq[++cnt]=a[i];
	}if(l!=0) sch[f]=l;
	else f--;
	if(r!=0) wsq[++cnt]=r;
	int ans=0,last=0,rast=0;
	for(int i=1;i<=f;i++){
		last+=sch[i];
		while(last>=wsq[sum]&&sum<=cnt){
			if(ch[i]==ch[n-sum+1]){
				last-=wsq[sum];
				sum++;
				continue;
			}last-=wsq[sum];
			ans+=wsq[sum];
			sum++;
		}if(last<wsq[sum]){
			wsq[sum]-=last;
			if(ch[i]!=ch[n-sum+1]){
				ans+=last;
			}last=0;
		}
	}cout<<ans;
	return 0;
}
