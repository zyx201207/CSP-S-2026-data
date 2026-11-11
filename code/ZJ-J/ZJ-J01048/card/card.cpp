#include<bits/stdc++.h>
using namespace std;

int n , m;
int a[500050];
int total[300050];
void card_play(int x)
{
	int now_tong[300050]={0};
	stack<int> play;
	for(int i=x;i<=n;i++)
	{
		if(now_tong[a[i]])
		{
			while(play.top()!=a[i])
			{
				now_tong[play.top()]--;
				play.pop();
			}
		}
		else
		{
			play.push(a[i]);
			now_tong[play.top()]++;
		}
	}
	while(!play.empty())
	{
		total[play.top()]++;
		play.pop();
	}
	return ;
}
int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++) card_play(i);
	for(int i=1;i<=m;i++) cout << total[i] <<" ";
	
	return 0; 
}
