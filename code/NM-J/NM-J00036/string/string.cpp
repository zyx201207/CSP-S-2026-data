#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
long long a1[N],st1[N];
char c1[N],c[N];
long long a[N],st[N];
long long len=0;
long long cnt=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	st1[1]=1;
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&a1[i],&c1[i]);
		st1[i+1]=st1[i]+a1[i];
		len+=a1[i];
	}
	long long mid;
	int midi;
	mid=len/2+1;
	bool flag=false;
	for(int i=1,j=1;i<=n;i++,j++){
		if(st1[i]<=mid && mid<st1[i]+a1[i] && a1[i]>1)
		{
			a[j]=mid-st1[i]+1,c[j]=c1[i],st[j]=st1[i];
			j++;
			a[j]=st1[i]+a1[i]-mid-1,c[j]=c1[i],st[j]=mid;
			midi=j;
			flag=true;
		}
		else{
			a[j]=a1[i],c[j]=c1[i],st[j]=st1[i];
		}
		//cout<<flag<<" ";
	}
	long long head=1,teil=len;
	int i=1,j=n;
	while(i<midi){
		if(st[i]+a[i]-head>teil-st[j]){
			if(c[i]!=c[j])
			cnt+=teil-st[j];
			head+=(teil-st[j]);
			teil-=(teil-st[j]);
			j--;
		}
		else if(st[i]+a[i]-head<teil-st[j]){
			if(c[i]!=c[j])
			cnt+=st[i]+a[i]-head;
			head+=(st[i]+a[i]-head);
			teil-=(st[i]+a[i]-head);
			i++;
		}
		else{
			if(c[i]!=c[j])
			cnt+=st[i]+a[i]-head;
			head+=(st[i]+a[i]-head);
			teil-=(st[i]+a[i]-head);
			i++;j--;
		}
		//cout<<cnt<<' ';
	}
	printf("%lld",cnt);
	return 0;
}
/*
3
2 a
2 b
1 c
*/
