#include<bits/stdc++.h>
using namespace std;
int a,b,m,n,s;
int main(){
freopen("card.in","r",stdin);
freopen("card.ans","w",stdout);
//我真求了，人做的？ 
cin>>m>>n;
int z[m],y[m],j[m],zd=0;
for(int i=0;i<m;i++){
	cin>>y[i];
}
for(int i=0;i<m;i++){
	s=0;
	for(int j=0;j<m;j++){
		z[j]=0;
	}
	for(int j=i;j<m;j++){
		for(int k=0;k<j;k++){
			if(z[j]=y[j])s=k;
		
		}
		if(s!=0){
			for(int k=s;k<m;k++)z[k]=0;
		
			zd=s-1;
			
		}
		else{
			z[s]=y[j];
		}
		for(int i=0;i<m;i++){
		cout<<z[i]; 
		}
		cout<<'\n';
		s=0;
	}
	
}
for(int i=0;i<m;i++){
	cout<<y[i]; 
}
fclose(stdin);
fclose(stdout);
}
