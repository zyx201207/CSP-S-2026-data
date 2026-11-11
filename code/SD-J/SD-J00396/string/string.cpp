#include<bits/stdc++.h>
using namespace std;
int n;
long long a[20005];
char c[20005];
long long cnt;
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		cnt+=a[i];
	}
	long long cnt1=0;
	long long cnt2=0;
	int xx=1;
	int yy=n; 
	if(cnt%2==0) cnt=cnt/2;
	else cnt=cnt/2+1;
	ans=cnt;
	while(cnt1<=cnt)
	{
		cnt2=cnt1+min(a[xx],a[yy]);
		if(cnt2>cnt){
			if(c[xx]-'a'==c[yy]-'a') ans=ans-(cnt-cnt1);
			cout<<ans<<endl;
			return 0;
		}
		if(c[xx]-'a'==c[yy]-'a') ans=ans-min(a[xx],a[yy]);
		if(a[xx]==a[yy]){
			cnt1+=a[xx];
			xx++;
			yy--;
		}
		else{
			if(a[xx]>a[yy]){
				a[xx]=a[xx]-a[yy];
				cnt1+=a[yy];
				yy--;
			}else{
				a[yy]=a[yy]-a[xx];
				cnt1+=a[xx];
				xx++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}


