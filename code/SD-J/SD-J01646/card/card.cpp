#include<bits/stdc++.h> 
using namespace std;
int n,c,m,cnt1,cnt2;
char cnt[100005];
char s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>c>>s;
		for(int j=0;j<c;j++){
			cnt[m]=s;
			m++;
		}
	}
	for(int i=0;i<m/2;i++){
		if(cnt[i]!=cnt[(m+1)/2+((m+1)/2)-i]){
			cnt1++;
		}
	}
	for(int i=(m+1)/2;i<n;i++){
		if(cnt[i]!=cnt[(m+1)/2-(i-((m+1)/2))]){
			cnt2++;
		}
	}
	if(cnt1>cnt2){
		cout<<cnt1;
	}else{
		cout<<cnt1;
	}
	return 0;
}

