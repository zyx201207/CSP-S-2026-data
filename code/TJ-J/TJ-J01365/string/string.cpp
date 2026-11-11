#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N],b[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	/*	int n,t=0;
	queue<int>q;
	cin>>n;string c;
	for(int i=1;i<=n;i++){
		int m;
		
		cin>>m>>c;
		t+=m;
		if(c=='a')for(int i=1;i<=m;i++)q.push(1);
		else if(c=='b')for(int i=1;i<=m;i++)q.push(2);
		else if(c=='c')for(int i=1;i<=m;i++)q.push(3);
		else if(c=='d')for(int i=1;i<=m;i++)q.push(4);
		else if(c=='e')for(int i=1;i<=m;i++)q.push(5);
		else if(c=='f')for(int i=1;i<=m;i++)q.push(6);
		else if(c=='g')for(int i=1;i<=m;i++)q.push(7);
		else if(c=='h')for(int i=1;i<=m;i++)q.push(8);
		else if(c=='i')for(int i=1;i<=m;i++)q.push(9);
		else if(c=='j')for(int i=1;i<=m;i++)q.push(10);
		else if(c=='k')for(int i=1;i<=m;i++)q.push(11);
		else if(c=='l')for(int i=1;i<=m;i++)q.push(12);
		else if(c=='m')for(int i=1;i<=m;i++)q.push(13);
		else if(c=='n')for(int i=1;i<=m;i++)q.push(14);
		else if(c=='o')for(int i=1;i<=m;i++)q.push(15);
		else if(c=='p')for(int i=1;i<=m;i++)q.push(16);
		else if(c=='q')for(int i=1;i<=m;i++)q.push(17);
		else if(c=='r')for(int i=1;i<=m;i++)q.push(18);
		else if(c=='s')for(int i=1;i<=m;i++)q.push(19);
		else if(c=='t')for(int i=1;i<=m;i++)q.push(20);
		else if(c=='u')for(int i=1;i<=m;i++)q.push(21);
		else if(c=='v')for(int i=1;i<=m;i++)q.push(22);
		else if(c=='w')for(int i=1;i<=m;i++)q.push(23);
		else if(c=='x')for(int i=1;i<=m;i++)q.push(24);
		else if(c=='y')for(int i=1;i<=m;i++)q.push(25);
		else if(c=='z')for(int i=1;i<=m;i++)q.push(26);
	}
	for(int i=1;i<=n;i++){
		cout<<q.front();
		q.pop();
	}
*/
	int n,t=0,ans=0;
	cin>>n;
    queue<string>q;
	string c;
	for(int i=1;i<=n;i++){ 
		int m;	
		cin>>m>>c;
		t+=m;
		b[i]=m;
		for(int j=1;j<=m;j++){
			q.push(c);			
		}
	}
	if(n==2){
    	if(c[0]==c[1]){
    		cout<<0;
    		return 0;
		}else{
			if(b[1]>=b[2]){
				ans+=b[2];
			}else ans+=b[1];				
		}
		cout<<ans;
		return 0;
	}
	if(n==1){
		cout<<0;
		return 0;
	}

	return 0;
}

