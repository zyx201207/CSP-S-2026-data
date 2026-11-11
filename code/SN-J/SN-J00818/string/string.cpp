//仲昶霖 SN-J00818 西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,d=0,f=0;
	string c,s[100005];
	cin >> n;
	if (n==1){
		cout << "0";
		return 0;
	} 
	for(int i=0 ;i<n ;i++){
		cin >> a >> c;
		for(int j=d;j<a+d;j++){
			s[j]=c;
			d+=a;
		}
	}
	if(n%2==0){
		for(int i=1; i<=n/2;i++){
			if(s[i]!=s[n-i]){
				f+=1;
			}
		}
	}else{
		for(int i=1; i<=n/2;i++){
			if(s[i]!=s[n-i]){
				f+=1;
			}
		}
	}
	cout << f;
	return 0;
}
