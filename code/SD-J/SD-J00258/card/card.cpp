#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[200005],cnt,c[200005],d[200005];
bool flag=true;
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		d[i]=a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(a[i]!=d[i]){
			flag=false;
		}
	}
	for(int i=1;i<=n;i++){
		b[1]=a[i];
		cnt=1;
		for(int j=i+1;j<=n;j++){
			if(flag){
					if(b[cnt]!=a[j]){
						b[++cnt]=a[j];
					}
			}else{
					int pos=0;
		        	for(int k=1;k<=cnt;k++){
			        	if(b[k]==a[j]){
			        		pos=k;
				        	break;
			        	}
		        	}
		        	if(pos==0){
			        	b[cnt+1]=a[j];
			        	cnt++;
			        }else{
				       cnt=pos;				       
		         	}
	    	}
     	for(int j=1;j<=cnt;j++){
     		c[b[j]]++;
		 }
		cnt=0;
		memset(b,0,sizeof(b));
    	}
    }
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
