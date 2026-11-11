#include<bits/stdc++.h>
using namespace std;
long long n,a[1000005],flag=0,cnt=0;
char s[1000005];
long long l,l1,r,r1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	l1=1,r1=n;
	l=a[l1],r=a[r1];
	while(l1<=r1){
		if(l1==r1){
			if(l>=r){
				break;
			}
		}
		if(s[l1]==s[r1]){
			if(l>r){
				l-=r;
				r1--;
				r=a[r1];
			}else if(l<r){
				r-=l;
				l1++;
				l=a[l1];
			}else{
				r1--;
				l1++;
				l=a[l1];
				r=a[r1];
			}
		}else{
			if(l>r){
				cnt+=r;
				l-=r;
				r1--;
				r=a[r1];
			}else if(l<r){
				cnt+=l;
				r-=l;
				l1++;
				l=a[l1];
			}else{
				cnt+=l;
				r1--;
				l1++;
				l=a[l1];
				r=a[r1];
			}
		}
	}
	cout<<cnt;
	return 0;
}
