#include<bits/stdc++.h>
using namespace std;
const int MAXG=6e7+10;
int w_n;
char w_s[MAXG];
int w_cnt;
int w_ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>w_n;
	for(int w_i=1;w_i<=w_n;w_i++)
	{
		int w_a;
		char w_c;
		cin>>w_a>>w_c;
		fill(w_s+w_cnt,w_s+w_cnt+w_a,w_c);
		w_cnt+=w_a;
	}
	for(int w_i=0;w_i<(w_cnt+1)/2;w_i++)
	{
		if(w_s[w_cnt-w_i-1]!=w_s[w_i])
		{
			w_ans++;
		}
	}
	cout<<w_ans;
	return 0;
}
