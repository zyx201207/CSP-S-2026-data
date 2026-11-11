#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	
	int n,m,x,cnt=0,maxt=-1;
	cin>>n>>m;
	int two[50][200010]={};

	for(int i=0;i<n;i++)
{
cin>>x;
while(x!=1){
 x/=2;
 cnt++;
 maxt=max(cnt,maxt);
}two[cnt][++two[cnt][0]]=x;
}for(int i=maxt;i>=0;i--){
   if(two[i][0]>=m){
   sort(&two[i][1],&two[i][two[i][0]],greater<int>());
   cout<<two[i][m];
   return 0;

}else{
	for(int j=1+two[i-1][0];j<=two[i][0];j++){
		two[i-1][j]=two[i][j-two[i-1][0]]/2;
	
	}


}

}

}
