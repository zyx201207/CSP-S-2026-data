#include<bits/stdc++.h>
using namespace std;
int la[200010];
char lb[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	if(n==1){
		cout << 0;
		return 0;
	}
	long long longa=0;
	int lsa=1,lsb=n;
	for(int i=1;i<=n;i++){
		cin >> la[i];
		longa+=la[i];
		cin >> lb[i];
	}
	long long vnt=0;
	for(int i=1;i<=n;i++){
		if(lb[lsa]!=lb[lsb]){
			vnt+=min(la[lsa],la[lsb]);
		} 
		if(la[lsa]<la[lsb]){
			la[lsb]-=la[lsa];
			lsa++;
		}
		else if(la[lsa]>la[lsb]){
			la[lsa]-=la[lsb];
			lsb--;
		} else{
			lsa++;
			lsb--;
			
		}
		if(lsa>=lsb) break;
	}
	cout << vnt;
	return 0;
}
