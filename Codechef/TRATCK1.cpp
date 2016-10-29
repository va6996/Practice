#include <iostream>
#include <map>
using namespace std;

int edges[1000], ranks[1000];

int findparent(int s){
	if(edges[s] == s)
		return s;
	return findparent(edges[s]);
}

void unionfind(int a, int b){
	int p = findparent(a);
	int q = findparent(b);
	if(p==q)
		return;
	else if(ranks[p] > ranks[q])
		edges[q] = p;
	else if(ranks[q] > ranks[p])
		edges[p] = q;
	else{
		edges[p] = q;
		ranks[p]++;
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int e, n, p, q;
		cin>>n>>e;
		for(int i=0;i<n;i++){
			edges[i] = i;
			ranks[i] = 0;
		}
		for(int i=0;i<e;i++){
			cin>>p>>q;
			unionfind(p-1, q-1);
		}
		map<int, int> diff;
		for(int i=0;i<n;i++)
			edges[i] = findparent(i);
		for(int i=0;i<n;i++){
			if(diff.count(edges[i]) > 0) ;
			else
				diff[edges[i]] = 1;
		}
		cout<<diff.size()-1<<endl;
	}
	return 0;
}