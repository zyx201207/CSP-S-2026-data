#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	long long a;
	string c;
}m[200005];
long long h,f,h1,f1,s,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m[i].a>>m[i].c;
	}
	h1=0;
	f1=n-1;
	h=m[h1].a;
	f=m[f1].a;
	while(1){
		if(h1>=f1){
			cout<<ans;
			return 0;
		}
		if(h==f){
			if(m[h1].c==m[f1].c){
				h1++;
				f1--;
				h=m[h1].a;
				f=m[f1].a;
			}
			else{
				ans+=m[h1].a;
				h1++;
				f1--;
				h=m[h1].a;
				f=m[f1].a;
			}
		}
		else{
			if(m[h1].c==m[f1].c){
				int yj=min(h,f);
				if(yj==h){
					h1++;
					h=m[h1].a;
					f=f-yj;
				}
				else{
					f1--;
					f=m[f1].a;
					h=h-yj;
				}
			}
			else{
				int jy=min(h,f);
				if(jy==h){
					ans+=jy;		
					h1++;
					h=m[h1].a;
					f=f-jy;
				}
				else{
					ans+=jy;		
					f1--;
					h=h-jy;
					f=m[f1].a;
				}
			}
		}
	}
	return 0;
}

