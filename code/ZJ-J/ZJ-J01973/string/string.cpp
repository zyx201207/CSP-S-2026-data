#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string l="";int sum=0;
	cin>>n;
	while(n--){
		int ll;
		char b;
		cin>>ll>>b;
		for(int i=0;i<ll;i++){
			l+=b;
		}
	}for(int i=0;i<l.size()/2;i++){
		if(l[i]!=l[l.size()-1-i]){
			sum+=1;
		}
	}cout<<sum;
	return 0;
	fclose(stdin);
	fclose(stdout);
}