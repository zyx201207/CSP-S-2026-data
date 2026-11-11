#include<bits/stdc++.h>
using namespace std;
string s;
long long ans,a[400010];
map<int,int> m;
int n;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		for(int j=0;j<a[i];j++) s+=c[i];
		a[i]+=a[i-1];
		m[a[i]]=1;
	}
	int num=n;
	for(int i=n;i<n*2;i++){
		int t=a[n-1]-a[i-n];
		if(!m[t]) a[num++]=t;
	}
	sort(a,a+num);
	int l,r;
	for(int i=1,j=num-2;i<=num/2&&j>=num/2-1;i++,j--){
		l=a[i]-1,r=a[j];
		if(s[l]!=s[r]) ans+=a[j+1]-a[j];
//		printf("l:%d  r:%d  %c  %c  ans:%d\n",l,r,s[l],s[r],ans);0
	}
	cout<<ans;
	return 0;
}
