#include<bits/stdc++.h>
using namespace std;
long long int n,a,lenn=0,cnt=0,flag=0;
char c[200020],d;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a >> d;
		lenn+=a;
		for(int j=lenn-a+1;j<=lenn;j++){
			c[j] = d;
		}
		
	}
	if(lenn%2==0){
		for(int i=1,j=lenn;i<=lenn/2;i++,j--){
			if(c[i]!=c[j]){
				cnt++;
				flag=1;	
			}
		}
		if(flag==0) cout << 0;
		else cout << cnt;
	}else{
		for(int i=1,j=lenn;i<=lenn/2+1;i++,j--){
			if(c[i]!=c[j]){
				cnt++;
				flag=1;
			}
		}
		if(flag==0) cout << 0;
		else cout << cnt;
	}
	//ceshishuju
	return 0;
}