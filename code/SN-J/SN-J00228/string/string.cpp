#include<bits/stdc++.h> 
using namespace std;
string s;
//struct S{
//	long long num;
//	char c;
//}a[200005];
int n;
//long long sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//  cin>>n;
//	for(int i = 1;i <= n;i++){
//		cin>>a[i].num >>a[i].c ;
//		sum+=a[i].num ;
//	}
//	int l = 1,r = n;
//	long long x = 0,ans = 0;
//	while(l <= r){
//		if(a[l].c != a[r].c ){
//			ans+=min(a[l].num,a[r].num )+x;
//			x = max(a[l].num,a[r].num )-min(a[l].num,a[r].num );
//		}
//		l++;r--;
//	}
    long long x,ans = 0;
    char c;
    cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>x>>c;
		while(x--){
			s+=c;
		}
	}
	long long l = 0,r = s.size()-1;
	while(l <= r){
		if(s[l] != s[r]){
			ans++;
		}
		l++;r--;
	}
	cout<<ans;

}
