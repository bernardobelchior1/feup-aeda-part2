/**
 * @file advertisement.h
 *
 * @brief Header file for class Advertisement*/

/**
 * @file advertisement.cpp
 *
 * @brief Code for class Advertisement*/


#ifndef ADVERTISEMENT_H
#define ADVERTISEMENT_H

#include<string>
#include<vector>

#include "../PtrUser/PtrUser.h"
#include "../../enums.h"
#include "../date/date.h"
#include "../user/user.h"
#include "../location/location.h"
#include "../proposal/proposal.h"
#include "../transaction/transaction.h"

using namespace std;
using namespace enums;

class User;//had to do this to allow cyclic calling of class
class Proposal;
class Transaction;
class PtrUser;

/**
 * @brief Advertisement class
 */
class Advertisement{
protected:
	unsigned int views; ///< Number of times the advertisement has been seen
	unsigned int id; ///< Advertisement identification number
	static unsigned int nextId; ///<Next advertisement identification number
	string title; ///< Advertisement title
	Category category; ///< Advertisement category
	string description; ///< Advertisement description
	Date creationDate; ///< Advertisement date of creation
	PtrUser *owner; ///< Pointer to owner of advertisement
	float price; ///< Price of product
	bool negotiable; ///< Whether price is negotiable or not
	bool featured; ///< Whether the creator of the ad paid our not to put is ad on the spotlight
	Date highlightEndDate; ///< The date while the ad going to be highlighted
public:
	/**
	 * @brief Constructor for class Advertisement
	 *
	 * @param owner Pointer to advertisement owner
	 * @param title Advertisement title
	 * @param category Advertisement category
	 * @param description Advertisement description
	 * @param price Product price
	 */
	Advertisement(PtrUser owner, string title, Category category, string description, float price);

	/**
	 * @brief Advertisement destructor
	 */
	virtual ~Advertisement();

	/**
	 * @brief Gets advertisement ID
	 *
	 * @return Returns advertisement ID
	 */
	unsigned int getId() const;

	/**
	 * @brief Gets advertisement owner
	 *
	 * @return Pointer to advertisement owner
	 */
	PtrUser getOwner();

	/**
	 * @brief Gets advertisement title
	 *
	 * @return Returns advertisement title
	 */
	string getTitle() const;

	/**
	 * @brief Gets advertisement category
	 *
	 * @return Returns advertisement category
	 */
	Category getCategory() const;

	/**
	 * @brief Gets advertisement description
	 *
	 * @return Returns advertisement description
	 */
	string getDescription() const;

	/**
	 * @brief Gets number of views the advertisement has had
	 *
	 * @return Returns views
	 */
	unsigned int getViews() const;

	/**
	 * @brief Gets advertisement price
	 *
	 * @return Returns advertisement price
	 */
	float getPrice() const;

	/**
	 * @brief Gets advertisement creation date
	 *
	 * @return Returns advertisement creation date
	 */
	string getCreationDate() const;

	/**
	 * @brief Gets date that highlight will finish
	 *
	 * @return Returns that date
	 */
	string gethighlightEndDate() const;

	/**
	 * @brief Returns if price is negotiable
	 *
	 * @return Returns whether the price is negotiable or not
	 */
	bool isPriceNegotiable() const;

	/**
	 * @brief Returns if user paid to ad be on the spotlight
	 *
	 * @return Returns whether the user paid or not
	 */
	bool hasUserPaid() const;

	/**
	 * @brief Changes the title
	 *
	 * @param newTitle is the new title
	 */
	void setTitle(string newTitle);

	/**
	 * @brief Changes creation date
	 *
	 * @param creationDate date of creation
	 */
	void setCreationDate(Date creationDate);

	/**
	 * @brief Changes the description
	 *
	 * @param newDescription is the new description
	 */
	void setDescription(string newDescription);

	/**
	 * @brief Sets negotiable attribute to value
	 *
	 * @param negotiable New value of negotiable attribute
	 */
	void setNegotiable(bool negotiable);

	/**
	 * @brief Sets category attribute to value
	 *
	 * @param newCategory New value of category attribute
	 */
	void setCategory(Category newCategory);

	/**
	 * @brief Sets price attribute to value
	 *
	 * @param newPrice New value of price attribute
	 */
	void setPrice(float newPrice);

	/**
	 * @brief Sets owner
	 *
	 * @param owner Owner
	 */
	void setOwner(PtrUser owner);

	/**
	 * @brief Sets the spotlight
	 *
	 * @param newValue new value of the flag
	 */
	void setFeatured(bool newValue);

	/**
	 * @brief Sets finish date of highlight
	 *
	 * @param newDate its new date that the highlight will end
	 */
	void sethighlightEndDate(Date newDate);

	/**
	 * @brief Extend duration of highlight
	 *
	 */
	void extendDurationHighligh(unsigned int duration);

	/**
	 * @brief Increments advertisement views
	 */
	void incrementViews();

	/**
	 * @brief Searches for text in advertisement
	 *
	 * @param text String to be search for in advertisement title and description
	 *
	 * @return Returns true if the text being searched for has been found. Returns false otherwise.
	 */
	bool searchForText(const string& text) const;

	/**
	 * @brief Returns a P if is a purchase ad or a S if is a sale ad
	 *
	 * @return Returns a char ( P(urchase) / S(ale))
	 */
	virtual char getType() const=0;

	/**
	 * @brief Gets ad owner location
	 *
	 * @return Returns ad owner location
	 */
	Location getLocation() const;

	/**
	 * @brief Compares two ads by they title
	 *
	 * @param ad Pointer to ad to compare with.
	 *
	 * @return Returns true if their titles match.
	 */
	bool operator==(Advertisement* ad) const;

	/**
	 * @brief Prints advertisement to out
	 *
	 * @param out Out stream
	 * @param ad Reference to advertisement to print
	 *
	 * @return Returns out stream
	 */
	friend ostream& operator<<(ostream& out, Advertisement &ad);

	/**
	 * @brief Reads advertisement to in
	 *
	 * @param in In stream
	 * @param ad Reference to advertisement to write on
	 *
	 * @return Returns in stream
	 */
	friend istream& operator>>(istream& in, Advertisement &ad);

	/**
	 * @brief Shows ad proposals
	 */
	virtual Transaction* viewProposals() = 0;

	/**
	 * @brief Add proposal
	 *
	 * @param p Proposal to add
	 */
	virtual void addProposal(Proposal* p) = 0;

	/**
	 * @brief Prints to out
	 *
	 * @param out Out stream
	 */
	virtual ostream& print(ostream& out) = 0;
};

#endif
