#include<bits/stdc++.h>
using namespace std;
int n,temp,len,t1sum,t2,t3=1;
char t;
string s;
struct L{
	int cnt;
	char num;
}g[200003],target[200003],end[200003];
bool check(string ss){
	string s2="";
	for(int i=(int)ss.size()-1;i>=0;i--){
		s2+=ss[i];
	}
		return s2==ss;
	
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
//	cin>>s;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&temp);
		cin>>t;
		for(int j=1;j<=temp;j++) s+=t;
		g[i].cnt=temp;
		g[i].num=t;
		len+=temp;
	}
	if(check(s)){
		printf("0");
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for( t2=1;t2<=n && t1sum+g[t2].cnt<=len/2;t2++){
		t1sum+=g[t2].cnt;
		target[t2].cnt=g[t2].cnt;
		target[t2].num=g[t2].num;
	}
	if(t1sum!=len/2){
		target[t2].cnt=len/2-t1sum;
		target[t2].num=g[t2].num;
		end[t3].cnt=g[t2].cnt-target[t2].cnt;
		t3++;
	}else t2-=1;
	for(;t3<=n;t3++){
		end[t3].cnt=g[(t1sum!=len/2?t2+t3-1:t2+t3)].cnt;
		end[t3].num=g[(t1sum!=len/2?t2+t3-1:t2+t3)].num;
	}
	//此时t2是目标连续数量,t3是end连续数量
	for(int i=1;i<=t2;i++) cout<<target[i].cnt<<" "<<target[i].num<<endl;
	for(int i=1;i<=t3;i++) cout<<end[i].cnt<<" "<<end[i].num<<endl;
//	for(int tarp=t2,int sp=(len%2==0?len/2+1:len/2+2);tarp>=1;){
//		
	//}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
