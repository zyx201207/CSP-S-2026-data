#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,m[100001],cnt1=0,cnt2=0,cnt3=0;
	char si,s1[100001],s2[100001];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m[i];
		cin>>si;
		for(int j=cnt1;j<cnt1+m[i];j++){
			s1[j]=si;
		}
		cnt1+=m[i];
	}
	for(int i=cnt1;i>=cnt1/2;i--){
		s2[cnt2]=s1[i];
		cnt2++;
	}
	for(int i=0;i<cnt1/2;i++){
		if(s1[i]!=s2[i]) cnt3+=1;
	}
	cout<<cnt3;
    fclose(stdin);
    fclose(stdout);
}
