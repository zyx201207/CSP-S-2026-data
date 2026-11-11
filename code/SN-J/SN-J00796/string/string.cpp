//考号:SN-J00796 学校：西安市临潼区铁炉初级中学  姓名：孙博元 
#include<bits/stdc++.h>
using namespace std;
int n;
long long leng,ans;
string s;
int main(){
	freopen("string.in", "r" , stdin);
	freopen("string.out", "w", stdout);
	cin>>n;
	int a,a2;
	char c[20005];
	bool flag = true;
	for(int i=1;i<=n;i++){
		cin>>a>>c[i];
		if(i==1)a2=a;
		else{
			if(a2!=a){
				flag = false;
			}
		} 
		for(int j=1;j<=a;j++)
			s+=c;
		leng += a;
	}
	if(flag==false){
		for(long long i=0;i<=leng/2;i++){
			if(s[i]!=s[leng-1-i]){
				ans++;
			}
		}	
	} else{
		for(int i=1;i<=n/2;i++){
			if(c[i]!=c[n-i+1]){
				ans+=a2;
			}
		}
	}
	cout<<ans;
	return 0;
}
