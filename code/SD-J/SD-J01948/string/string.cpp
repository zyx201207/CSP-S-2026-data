#include <bits/stdc++.h>
using namespace std;
long long  n,l=0,a,r=0,cnt=0,b[200000];
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		cin>>c;
		s[l]=c;
		b[l]=a;
		l++;
	}
	l--;
	while(l>r){
		if(s[l]==s[r]){
			if(b[l]>b[r]){
				b[l]-=b[r];
				r++;
			}else if(b[l]<b[r]){
				b[r]-=b[l];
				l--;
			}else{
				l--;
				r++;
			}
		}else{
			cnt+=min(b[l],b[r]);
			if(b[l]>b[r]){
				b[l]-=b[r];
				r++;
			}else if(b[l]<b[r]){
				b[r]-=b[l];
				l--;
			}else{
				l--;
				r++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
