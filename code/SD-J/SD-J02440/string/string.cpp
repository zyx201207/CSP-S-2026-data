#include<bits/stdc++.h>
using namespace std;
string s,l;
long long n,a,len,cnt;
bool fun=1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while (n--){
		cin>>a>>l;
		while (a--){
			s+=l;
		}
	}
	len=s.size();
	for(int i=0;i<len;i++){
		if (s[i]!=s[len-1-i]){
			fun=0;
		}
	}
	if (fun){
		cout<<0;
		return 0;
	}
	for(int i=0;i<len;i++){
		if (s[i]!=s[len-1-i]){
			s[i]=s[len-1-i];
			cnt++;
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}







