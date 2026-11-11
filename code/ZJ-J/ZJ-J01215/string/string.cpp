#include <bits/stdc++.h>

using namespace std;
const int N=2e5+5;
int n,len;
long long a[N];
char c[N];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long sum=0;
	for(int i=1;i<=n;i++){
		int x;char ch;
		cin>>x>>ch;
		sum+=x;
		if(i!=1&&ch==c[len]){
			a[len]+=x;
		}else{
			c[++len]=ch;
			a[len]=x;
		}
	}
	if(len==1){
		cout<<0;return 0;
	}
	if(sum<=10000000){
		string s;
		for(int i=1;i<=len;i++){
			for(int j=1;j<=a[i];j++){
				s+=c[i];
			}
		}
		long long ans=0;
		for(int i=0,j=sum-1;i<=j;i++,j--){
			if(s[i]!=s[j])ans++;
		}
		cout<<ans;
		return 0;
	}
	int i=1,j=len;
	long long cnt1=a[1];
	long long cnt2=0;
	long long ans=0,last=0;
	while(i<j){
		while(cnt2+a[j]<=cnt1){
			cnt2+=a[j];
			if(c[i]!=c[j])ans+=a[j];
			j--;
		}
		if(cnt2==cnt1){
			i++;cnt1+=a[i];continue;
		}
		last=a[j];
		while(cnt2+last>cnt1){
			if(c[j]!=c[i]){
				ans+=cnt1-cnt2;
			}
			last=cnt2+last-cnt1;
			cnt2=cnt1;
			i++;
			cnt1+=a[i];
		}
		cnt2+=last;
		if(cnt2==cnt1)i++,cnt1+=a[i],j--;
		else j--;
	}
	cout<<ans;
	return 0;
}
