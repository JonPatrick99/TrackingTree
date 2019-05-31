// TrackingTree.h
// Jon Caldwell
// Project 2: Tracking Tree


#include "TTnode.h"


class TrackingTree
{
public:

	TrackingTree();

	TTnode* getTree();

	void setTree(TTnode* in);								

	int insertNode(TTnode* cur, string in);					
	bool isFull(TTnode* in);								
	int height(TTnode* in);								
	void changeCrawl(int height);							
	vector<TTnode*> nodesAtH(TTnode* curTree, int height);	
	void showNode(TTnode* inTree, string id);				
	void changeNode(TTnode* inTree, string id, string raw);	


private:

	TTnode* tree;

};
