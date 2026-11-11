#include<bits/stdc++.h>
using namespace std;
int n,m,sum[300003];
string s,r;
int t;
char temp;
string de(string ss,int from){
	string s1="";
	for(int i=0;i<=from-1;i++) s1+=ss[i];
	for(int i=from+1;i<(int)ss.size();i++) s1+=ss[i];
	return s1;
}
int main(){
	cout<<"ok";
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&t);
		s+=to_string(t);
		cout<<s<<endl;
	}
//	cout<<"ok";
	for(int i=1;i<=n;i++){
		r=s;
		cout<<"r="<<r;
		for(int j=i-1;j<=(int)s.size()-1;){
			temp=r[j];
			de(r,j);
//			cout<<"r="<<r<<endl;
			if((int)r.find(temp)==-1){
				r+=temp;
			}else{
				r.erase((int)r.find(temp));
				r+=temp;
			}
		}
		for(int j=1;j<=m;j++){
				if((int)r.find(j)!=-1) sum[j]++;
			}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",sum[i]);
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
