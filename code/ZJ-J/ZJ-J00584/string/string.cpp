#include<bits/stdc++.h>
#define lll long long
using namespace std;

string ss;
lll a[200010];
char c[200010];
lll mx,n,s[200010],ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i]>>c[i];
		mx=max(mx,a[i]);
		s[i]=s[i-1]+a[i];
	}
	if(mx*n>100000000){
		lll l=0,r=s[n],ll=1,rr=n;
		while(l<=r&&ll<=rr&&l<=s[n]/2&&r>=s[n]/2){
			if(c[ll]==c[rr]){
				if((s[ll]-l)>(r-s[rr-1])){
					l+=a[rr];
					r-=a[rr];
					rr--;
				}else if((s[ll]-l)<(r-s[rr-1])){
					l+=a[ll];
					r-=a[ll];
					ll++;
				}else if((s[ll]-l)==(r-s[rr-1])){
					l+=a[ll];
					r-=a[ll];
					ll++;
					rr--;
				}
			}
			if(c[ll]!=c[rr]){
				if((s[ll]-l)>(r-s[rr-1])){
					l+=a[rr];
					r-=a[rr];
					ans+=a[rr];
					rr--;
				}else if((s[ll]-l)<(r-s[rr-1])){
					l+=a[ll];
					r-=a[ll];
					ans+=a[ll];
					ll++;
				}else if((s[ll]-l)==(r-s[rr-1])){
					l+=a[ll];
					r-=a[ll];
					ans+=a[ll];
					ll++;
					rr--;
				}
			}
		}
		cout<<ans;
	}else{
		ss=" ";
		lll sum=0;
		for(lll i = 1;i<=n;i++){
			sum+=a[i];
			for(int j = 1;j<=a[i];j++){
				ss+=c[i];
			}
		}
		lll l=1,r=sum;
		while(l<=r){
			if(ss[l]!=ss[r]){
				ans++;
			}
			l++;
			r--;
		}
		cout<<ans;
	}
	return 0;
}

