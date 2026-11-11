#include<bits/stdc++.h>
using namespace std;
long long n=0,l=0,i=1,m=0,h=0;
string s="0";
long long a[100005]={0};
char c[100005]={' '};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>a[i]>>c[i];
		l+=a[i];
		while(a[i]--){
			s+=c[i];
		}
	}
	if(l%2==0){
		m=l/2;
		i=m+1;
		while(m--){
			if(s[m]!=s[i]){
				h++;
			}
			i++;
		}
	}else{
		m=l/2;
		i=m+2;
		while(m!=0){
			if(s[m]!=s[i]){
				h++;
			}
			i++;
			m--;
		}
	}
	cout<<h;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
