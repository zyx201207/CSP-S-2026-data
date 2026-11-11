#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c)  cout<<1;  // 在同一个车厢 
	else{
	   cout<<0<<0<<0<<0;
	   return 0;
	}
	int id1=b[b.size()-1];
	for(int i=b.size()-1;i>=0;i--){
		id1+=(b[i-1]-'0')*10;
	}
	int id2=d[d.size()-1];
	for(int i=d.size()-1;i>=0;i--){
	    id2+=(d[i-1]-'0')*10;
	}
	int id3=b[1];
	for(int i=1;i>=0;i--){
		id3+=(b[i-1]-'0')*10;
	}
	int id4=d[1];
	for(int i=1;i>=0;i--){
	    id4+=(d[i-1]-'0')*10;
	}
	if(a==c&&id3==id4)  cout<<1;  // 在同一排 
	else{
	   cout<<0<<0<<0;
	   return 0;
	} 
	if(a==c&&id3==id4&&abs((b[b.size()-1]-'0')-(d[b.size()-1]-'0'))<=2&&(b[b.size()-1]!='C'&&d[b.size()-1]!='D')&&(b[b.size()-1]!='D'&&d[b.size()-1]!='C'))  cout<<1;  // 在同一侧
	else{
	   cout<<0<<0;
	   return 0;
	} 
	if(a==c&&id3==id4&&abs((b[b.size()-1]-'0')-(d[b.size()-1]-'0'))<=2&&(b[b.size()-1]!='C'&&d[b.size()-1]!='D')||(b[b.size()-1]!='D'&&d[b.size()-1]!='C')&&abs(id1-id2)==1)  cout<<1;  // 相邻 
	else  cout<<0;
	return 0;
}
