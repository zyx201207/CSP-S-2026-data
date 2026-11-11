#include<bits/stdc++.h>
using namespace std;

char o;
string s,sl,sr;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n,a,cnt1=0,cnt2=0;
	scanf("%d",&n);
	
	for(int i=0;i<n;++i){
		scanf("%d %c",&a,&o);
		for(int j=0;j<a;j++){
			s[i+j]=o;
		}
		
	}
	int l=s.length();
	if(l%2==0){
		for(int i=0;i<l/2;++i){
			sl[i]=s[i];
		}for(int i=l/2;i<l;++i){
			sr[i]=s[i];
		}
		for(int i=0;i<l/2;++i){
			if(sl[i]!=sr[i]){
				cnt1++;
			}
		}
	}else{
		int l1=l-1,l2=l1/2+1;
		for(int i=0;i<l1/2;++i){
			sl[i]=s[i];
		}for(int i=l1/2+1;i<l;++i){
			sr[i]=s[i];
		}
		for(int i=0;i<l1/2;++i){
			if(sl[i]!=sr[i]){
				cnt2++;
			}
		}
	}
	printf("%d",min(cnt1,cnt2));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
