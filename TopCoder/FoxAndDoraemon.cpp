/*input
6 100
1712 1911 1703 1610 1697 1612
*/
// https://community.topcoder.com/stat?c=problem_statement&pm=11860
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mp make_pair
#define el "\n"
#define pb push_back
#define pp push
#define inf 1000000007

priority_queue< int , vector<int> , greater<int> > pq;

class FoxAndDoraemon{
public:
int minTime(vector <int> c, int split)
{
	for(int i=0;i<c.size();i++)
	{
		pq.pp(c[i]);
	}
	while(pq.size()>1)
	{
		pq.pop();
		int x=pq.top();
		pq.pop();
		pq.pp(split+x);
	}
	return pq.top();
}
};