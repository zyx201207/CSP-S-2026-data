#include<bits/stdc++.h>
using namespace std;
struct abc{
	long long len;
	char c;
}a[301000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin >> n;
	string s="";
	for(int i=1;i<=n;i++){
		cin >> a[i].len >> a[i].c;
	}
	long long cnt = 0;
	long long l=1,r=n;
	while(l<r){
		if(a[l].c==a[r].c){
			if(a[l].len>a[r].len){
				a[l].len-=a[r].len;
				
				r--;
			}else{
				a[r].len-=a[l].len;
				
				l++;
			}
		}else{
			cnt+=min(a[l].len,a[r].len);
			if(a[l].len>a[r].len){
				a[l].len-=a[r].len;
				
				r--;
			}else{
				a[r].len-=a[l].len;
				
				l++;
			}
		}
	}
	cout << cnt;
	return 0;
} 
