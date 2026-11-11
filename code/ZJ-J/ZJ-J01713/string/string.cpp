#include<bits/stdc++.h>
using namespace std;
string a,l;
long long c,n;
bool res(string uuu){
	string yu;
	long long chang = uuu.length();
	for(long long i = chang -1;i >=0 ;i--){
		yu += uuu[i];
	} 
	if(yu == uuu){
		return true;
	}else{
		return false;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(long long i = 1;i <= n;i++){
		cin >> c;
		cin >>a;
		for(long long i = 1;i <= c;i++){
			l += a;
		} 
	}

	long long zc = l.length();
   
	for(long long i = 0;i < (zc+1) / 2;i++){
		string hhh;
		for(int j = i;j < zc-i;j++){
			hhh += l[j];
		}
	
		
		if(res(hhh)){
			cout << i;
			break; 
		}
		
	} 
	
	
}
