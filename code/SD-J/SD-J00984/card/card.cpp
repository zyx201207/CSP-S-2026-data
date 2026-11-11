# include<bits/stdc++.h>
using namespace std;
const int N = 5*1e5+5;
int n,m,f[N],a[N];
queue<int> q;
string s;
int finds(int x){
	for(int i=0;i<s.size();i++){
		if(s[i]-'0'==x){
			return i;
		}
	}
	return -1;
}
int main(void){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int v=0;v<n;v++){
		for(int i=v;i<n;i++){
			q.push(a[i]);
		}
		while(!q.empty()){
			int t = q.front();
			q.pop();
			int tmp = finds(t);
			if(tmp!=-1){
				s[tmp+2] = ' '; 
				s[tmp] = ' ';
			}
			s += to_string(t);
			s += ' ';
		}
		
		//cout<<s<<endl;
		
		for(int i=0;i<s.size();i++){
			int t = 0;
			int j=i;
			int tmp = 1;
			while(s[i]!=' '){
				t += (tmp)*(s[j]-'0');
				j++;
				i++;
				tmp++;
			}
//			printf("\nt:%d\n",t);
			f[t]++;
		}
		s = "";
	}
	
	for(int i=1;i<=m;i++){
		printf("%d ",f[i]);
	}
	return 0;
}
