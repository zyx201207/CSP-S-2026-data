#include <bits/stdc++.h>
using namespace std;
long long n,l,r,cnt;
int a[100000],b[100000];
bool bo;
string s;
char c[100000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i] = a[i];
		cin>>c[i];
	}
	sort(b+1,b+n+1);
	if(b[1]==b[n]) bo = true;
	if(!bo){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];j++){
				s = s+c[i];
			}
		}
	}else{
		for(int i=1;i<=n;i++){
			s = s+c[i];
		}
	}
	r = s.size()-1;
	while(l<=r){
		if(s[l]!=s[r]) cnt++;
		l++;
		r--;		
	}
	if(bo) cnt = cnt*a[1];
	printf("%d",cnt);
	return 0;
}
