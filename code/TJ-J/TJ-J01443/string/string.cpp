#include<bits/stdc++.h>
using namespace std;
int i,ii,jj,j,n,z,a[10086],l,m,o;
struct node{
	int x;
	char y;
}s[200086];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	cin>>s[1].x>>s[1].y;
	for(int k=2;k<=n;k++){
		cin>>s[k].x>>s[k].y;
	
	}
	i=1;
	j=n;
	ii=1;
	jj=s[n].x;
	//cout<<s[n].x<<endl;
	while(i<j||(i==j&&ii<jj)){
		//cout<<i<<" "<<ii<<" "<<j<<" "<<jj<<" "<<endl;
		if(s[i].y!=s[j].y){
			l=min(jj,s[i].x-ii+1);
			//cout<<'Y'<<l<<endl;
			for(int k=100;k>=1;k--){
				a[k]+=l;
				
				
				l=a[k]/10;
				a[k]%=10;
				//cout<<a[k];
				if(l==0)break;
			}
		}
		m=min(jj,s[i].x-ii+1);
		//cout<<'Z'<<m<<endl;
		jj-=m;
		//cout<<jj<<endl;
		while(jj<=0){
			j--;
			jj+=s[j].x;
		}
		ii+=m;
		//cout<<ii<<endl;
		while(ii>s[i].x){
			i++;
			ii-=s[i-1].x;
		}
	}
	//cout<<'X'<<" "<<i<<" "<<ii<<" "<<j<<" "<<jj<<" "<<m<<endl;
	for(o=1;o<=100;o++){
		if(a[o]!=0)break;
	}
	if(o>100)cout<<0;
	for(;o<=100;o++){
		cout<<a[o];
	}
	return 0;
}
