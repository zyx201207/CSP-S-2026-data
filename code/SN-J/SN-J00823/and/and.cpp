#include<bits/stdc++.h>
using namespace std;
struct d{
	string r;
};
int a[100],n,m,t;
d b[1000];
string h(int a){
	string s;
	for(int i=31;i>=0;i--){
		t=0;
		for(int j=0;j<n;j++){
			if(b[i].r[j]=='1'){
				t++;
			}
		}
		if(t>=m){
			s+='1';
			for(int j=0;j<31;j++){
				if(b[i].r[j]!='1'){
					b[i].r='0';}
				}
		}else{
			s+='0';
		}
	}
}
string e(int a){
	string s;
	while(a>=2){
		s+=a%2+'0';
		a/=2;
	}
	return s+'1';
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i].r=e(a[i]);
	}
	if(m==1){
		sort(a,a+n);
		cout<<a[n-1];
		return 0;
	}
	string s=h(31);
	double ans;
	for(int i=0;i<31;i++){
		ans+=(s[i]-'0')*pow(2,32-i-1);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
