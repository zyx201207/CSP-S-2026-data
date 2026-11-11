#include<iostream>
#include<cstring>
using namespace std;
bool b(string x,string y);
bool b_2(string x,string y);
bool b(string x,string y){
	return (x[2]>'C')&&(y[2]>'C');
}
bool b_2(string x,string y){
	return (x[2]<='C')&&(y[2]<='C');
}
int main(){
   freopen("travel.in","r",stdin);
   freopen("travel.out","w",stdout);
   struct travel{
	   string chexiang;
	   string zuoweihao;
   }a[2];
   for(int i=0;i<2;i++){
	   cin>>a[i].chexiang;
	   cin>>a[i].zuoweihao;
   }
   string s="0000";
   int c=(a[0].zuoweihao[0]-'0')*10+(a[0].zuoweihao[1]-'0');
   int d=(a[1].zuoweihao[0]-'0')*10+(a[1].zuoweihao[1]-'0');
   bool c_2=b(a[0].zuoweihao,a[1].zuoweihao);
   bool d_2=b_2(a[0].zuoweihao,a[1].zuoweihao);
   if(a[0].chexiang==a[1].chexiang){
	   s[0]='1';
	   if(c==d){
		   s[1]='1';
		   if(c_2||d_2){
			   s[2]='1';
			   if((a[0].zuoweihao[2]-a[1].zuoweihao[2])==-1||(a[0].zuoweihao[2]-a[1].zuoweihao[2])==1){
				   s[3]='1';
			   }
		   }
	   }
   }
   cout<<s;
   return 0;
  }
