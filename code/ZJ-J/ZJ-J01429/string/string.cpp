#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a[200005];
	char c[200005];
	long long k=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		k=k+a[i];
	}
	long long x;
	if(k%2==0)x=k/2;
	else x=(k-1)/2;
	long long ans=0;
	long long cnt1=0,cnt2=0,i1=n;
	for(int i=1;cnt1!=x;i++){
		cnt1+=a[i];
		if(cnt1>x)cnt1=x;
		while(cnt1>cnt2){
			if(cnt2+a[i1]>cnt1){
				if(c[i]!=c[i1])ans+=cnt1-cnt2;
				cnt2=cnt1;
			}else{
				if(c[i]!=c[i1])ans+=a[i1];
				cnt2+=a[i1];
			}
			i1++;
		}
	}
	cout<<ans;
    fclose(stdin);
	fclose(stdout);
	return 0;
}
