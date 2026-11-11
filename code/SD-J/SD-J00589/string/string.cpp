#include <bits/stdc++.h>
using namespace std;
int const maxn=2*100000+1000;
int n,num,a[maxn];
long long cnt = 0;
char c[maxn];
string s1,s2;
int ifprint_mode,ifprint_num,ifprint_now,ifprint_string;
char ifprint_char;
int if_string(){
	int a1[maxn];
	char c1[maxn];
	for(int i=0;i<n;i++){
		a1[i]=a[i],c1[i]=c[i];
	}
	for(int i=0,j=n-1;i<n,j>=0;i++,j--){
		int str_longth = a1[i];
		if(c1[i]!=c1[j]){
			ifprint_mode = 1;
			ifprint_num = str_longth;
			ifprint_char = c1[i];
			ifprint_now = j;
			ifprint_string = i;
			return 0;
		}
		if(a1[j]<str_longth&&c1[j-1]!=c1[j]){
			ifprint_mode = 2;
			ifprint_num = a1[j]+a1[j-1]-str_longth;
			ifprint_char = c1[j];
			ifprint_now = j;
			return 0;
		}
		else if((a1[j]+a1[j-1]>=str_longth)&&c1[j-1]==c1[j]&&a1[j]<str_longth){
			a1[j-1]=a1[j]+a1[j-1]-str_longth;
		}
	}
	return 1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	while(1){
		if(if_string()==1){
			break;
		}
		else{
			if(ifprint_mode == 1){
				if((c[ifprint_now-1]==ifprint_char)&&((ifprint_now-1)!=(ifprint_string))&&(ifprint_num>a[ifprint_now-1])){
					cnt += ifprint_num-a[ifprint_now-1];
					a[ifprint_now] = ifprint_num-a[ifprint_now-1];
					c[ifprint_now] = ifprint_char;
				}
				else{
					cnt += (int)ifprint_num;
					a[ifprint_now] = ifprint_num;
					c[ifprint_now] = ifprint_char;
				}
			}
			if(ifprint_mode == 2){
				cnt += ifprint_num;
				a[ifprint_now-1] = ifprint_num;
				c[ifprint_now-1] = ifprint_char;
			}
		}
	}
	cout<<cnt;
	return 0;
} 
