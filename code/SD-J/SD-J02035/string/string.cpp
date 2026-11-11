#include<bits/stdc++.h>
using namespace std;
typedef long long llt;
	int n,hd,tl;
	llt a[200005],st,ed,bj1,bj2,lbj1,lbj2,sl;
	char ch[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>ch[i];
		ed+=a[i];
	}
	hd=0;
	tl=n+1;
	st=0;
	ed++;
	bj1=0;
	bj2=0;
	while(tl-hd>1){
		if(bj1<=bj2){
			lbj1=bj1;
			hd++;
			bj1+=a[hd];
			st+=a[hd];
			if(bj1<=bj2){
				if(ch[hd]!=ch[tl]){
					sl+=a[hd];
				}
			}
			else{
				if(ch[hd]!=ch[tl]){
					sl+=(a[hd]-(bj1-bj2));
				}
			}
		}
		else{
			lbj2=bj2;
			tl--;
			bj2+=a[tl];
			ed-=a[tl];
			if(bj1>bj2){
				if(ch[hd]!=ch[tl]){
					sl+=a[tl];
				}
			}
			else{
				if(ch[hd]!=ch[tl]){
					sl+=(a[tl]-(bj2-bj1));
				}
			}
		}
	}
	cout<<sl;
	
	
	
	
	
	
	
	return 0;
} 
/*

*/
